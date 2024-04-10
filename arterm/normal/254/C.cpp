#include <fstream>
#include <string>

#define M 30

using namespace std;


ifstream cin ("input.txt");
ofstream cout("output.txt");


string s,t;
long n,f[M],h[M],p[M],ans=0;

void solve(void){
    for (long i=0; i<n; ++i)
    f[t[i]-'A']++;
    for (long i=0; i<n; ++i)
    h[s[i]-'A']++;

    for (long x,i=0; i<n; ++i){
        x=s[i]-'A';
        if (p[x]==f[x]){
            for (long j=0; j<M; ++j)
            if (f[j]>p[j]+h[j]){
                s[i]=j+'A';
                p[j]++;
                h[x]--;
                ans++;
                break;
            }
            continue;
        }
        if (p[x]+h[x]>f[x]){
            for (long j=0; j<x; ++j)
            if (f[j]>p[j]+h[j]){
                s[i]=j+'A';
                p[j]++;
                h[x]--;
                ans++;
                break;
            }
            if (s[i]==x+'A')
            p[x]++,h[x]--;
        }


    }
    cout<<ans<<"\n";
    cout<<s;


}


int main()
{
    cin>>s>>t;
    n=s.length();
    solve();

    return 0;
}