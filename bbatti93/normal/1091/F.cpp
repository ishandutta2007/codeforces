#include <bits/stdc++.h>

using namespace std;

long long n, ki=0, t[100001], gr=0, wa=0;
string s;
long long f[100001];
bool vw=false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++) cin >> t[i];
    cin >> s;
    for(int i=0;i<n;i++) {
        if(s[i]=='W') f[i]=0;
        if(s[i]=='G') f[i]=1;
        if(s[i]=='L') f[i]=2;
    }
    for(int i=0;i<n;i++) {
        if(f[i]==0) {
            wa+=t[i];
            ki+=2*t[i];
            vw=true;
        }
        if(f[i]==1) {
            long long w=min(wa,t[i]);
            t[i]-=w;
            wa-=w;
            ki+=2*w;
            gr+=2*w;
            gr+=t[i];
            ki+=3*t[i];
        }
        if(f[i]==2) {
            long long w=min(wa,t[i]);
            t[i]-=w;
            wa-=w;
            ki+=2*w;
            long long g=min(gr,t[i]);
            t[i]-=g;
            gr-=g;
            ki+=3*g;
            long long m=4;
            if(!vw) m+=2;
            ki+=m*t[i];
        }
    }
    cout << ki << endl;
    return 0;
}