#include<bits/stdc++.h>
//#define ll int
#define ll long long
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define yn idehfushefuwheuf
#define y1 issdehfushefuwheuf
#define endL "\n"
#define all(a) a.begin(),a.end()
#define p_b push_back
#define pll pair<ll,ll>
#define vout(a); cout<<a;return 0;
#define sqr(a) ((a)*(a))


const ll gig = 1e18;
const ll gg = 25*1e6;


using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen("1.out", "r", stdin);
//    freopen("1.out", "w", stdout);

    ll n;
    string s, s1;
    vector<ll> ot;
    cin >> n;
    cin >> s >> s1;

    for (int i = 0; i < s.size(); i++) {
        int j;
        for (j = i; j < s.size(); j++) if (s[j] == s1[i]) break;
        ll o = j;
        if (j == s.size()) {
            cout << -1;
            return 0;
        }
        for (int j = o - 1;  i <= j; j--) {
            ot.p_b(j);
            swap(s[j], s[j + 1]);
        }
    }
    cout << ot.size() << endL;
    for (int i = 0; i < ot.size(); i++) cout << ot[i] + 1 << " ";


}