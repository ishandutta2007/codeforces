/// Black lives matter
#include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef int ll;
typedef complex<double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100;
char a[N],b[N];
int Main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll t1=0;
    for (int i=0;i<s.size();i++) if (s[i]=='1') t1++;
    if (t1%2==1) kill("NO");
    ll z=0;
    for (int i=0;i<n;i++){
        if(s[i]=='1'){
            if (z<t1/2) z++,a[i]='(';
            else a[i]=')';
        }
    }
    z=0;
    for (int i=0;i<n;i++){
        b[i]=a[i];
        if (s[i]=='0'){
            if (z%2==0) a[i]='(',b[i]=')';
            else a[i]=')',b[i]='(';
            z++;
        }
    }
    ll cnt1=0;
    ll cnt=0;
    for (int i=0;i<n;i++){
    //    cout << a[i];
        if (a[i]=='(') cnt1++;
        else cnt1--;
        if (b[i]=='(') cnt++;
        else cnt--;
        if (cnt1<0 || cnt<0) kill("NO");
    }
    cout << "YES" << endl;
    for (int i=0;i<n;i++) cout << a[i];
    cout << endl;
    for (int i=0;i<n;i++) cout << b[i];
    cout << endl;
    return 0;
}
int32_t main(){
    sync;
    ll t=1;
    cin >> t;
    while(t--) Main();
}