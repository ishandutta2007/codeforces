#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define mp make_pair

void print(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cout<<a[i]<<' ';
    cout<<endl;
}

void get(vector<auto> &a)
{
    for (int i = 0; i<a.size(); i++) cin>>a[i];
}

ll p = 1e9 + 7;

ll mul(ll a, ll b) {
    return (1LL * a%p * b%p) % p;
}

ll add(ll a, ll b) {
    ll s = (a+b);
    s = s%p;
    if (s<0) s+=p; 
    return s;
}

int po(int a, int deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}

int inv(int n)
{
    return po(n, p-2);
}

mt19937 rnd(228);

int dig(char c)
{
    return c - '0';
}

int sec()
{
    string s;
    cin>>s;
    int answer = 0;
    answer+=36000*dig(s[0]);
    answer+=3600*dig(s[1]);
    answer+=600*dig(s[3]);
    answer+=60*dig(s[4]);
    answer+=10*dig(s[6]);
    answer+=dig(s[7]);
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, t;
    cin>>n>>m>>t;
    vector<int> q(n);
    for (int i = 0; i<n; i++) q[i] = sec();
    bool check = false;
    for (int i = 0; i<n-m+1; i++) if (q[i]+t-1>=q[i+m-1]) check = true;
    if (!check) {cout<<"No solution"; return 0;}
    
    set<pair<int, int>> gopa; //form (timestop, idx)
    
    //vector<int> stop(20001);
    vector<int> started(86400);
    for (int i = 0; i<n; i++) started[q[i]]++;
    //print(started);
    int counter = 1;
    int online = 0;
    vector<int> answer;
    for (int i = 0; i<86400; i++)
    {
        while (gopa.size()>0&&(gopa.begin()->first)<i) {gopa.erase(gopa.begin()); online--;}
        while (online<m&&started[i])
        {
            gopa.insert(mp(i + t - 1, counter)); 
            //stop[counter] = i + t - 1;
            answer.push_back(counter);
            counter++;
            started[i]--;
            online++;
        }
        if (started[i])
        {
            auto it = gopa.end();
            it--;
            int curend = it->first;
            int curidx = it->second;
            for (int j = 0; j<started[i]; j++) answer.push_back(curidx);
            gopa.erase(mp(curend, curidx));
            gopa.insert(mp(i+t-1, curidx));
            //stop[curidx] = i + t - 1;
        }
    }
    cout<<counter-1<<endl;
    for (int i = 0; i<answer.size(); i++) cout<<answer[i]<<endl;

}