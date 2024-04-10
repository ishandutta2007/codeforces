#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
using namespace std;

typedef long long ll;
typedef long double ld;
const int N = 1000;
const ll INF = 200000000000000000ll;

int main() {
    //freopen("input.txt", "r", stdin);
    map <ll, ll> s1;
    set <ll> st1;
    map <ll, ll> s2;
    set <ll> st2;
    ll w, h, n;
    cin >> w >> h >> n;
    s1[-w] = 1;
    s2[-h] = 1;
    st1.insert(0);
    st1.insert(w);
    st2.insert(0);
    st2.insert(h);

    char ch;
    ll t;
    for (ll i = 0; i < n; i++)
    {
        cin >> ch >> t;
        if (ch == 'H')
        {
            st2.insert(t);
            set <ll> :: iterator it = st2.find(t);
            ll m1 = *(--it);
            it++;
            ll m2 = *(++it);
            //cout << m1 << "  !  " << m2 << endl;
            s2[-(abs(m1 - m2))]--;
            if (!s2[-(abs(m1 - m2))])
                s2.erase(-(abs(m1 - m2)));
            s2[-abs(m1 - t)]++;
            s2[-(abs(t - m2))]++;
        }
        else
        {
            st1.insert(t);
            set <ll> :: iterator it = st1.find(t);
            ll m1 = *(--it);
            it++;
            ll m2 = *(++it);
            s1[-(abs(m1 - m2))]--;
            if (!s1[-(abs(m1 - m2))])
                s1.erase(-(abs(m1 - m2)));
            s1[-abs(m1 - t)]++;
            s1[-(abs(t - m2))]++;
        }
        //for (map<ll, ll> :: iterator it = s1.begin(); it != s1.end(); it++)
          //  cout << it->first << " " << it->second << endl;
        //cout << endl;
        cout << s1.begin()->first * s2.begin()->first << endl;
    }

}