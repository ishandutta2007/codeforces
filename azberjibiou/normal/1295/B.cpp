#include <bits/stdc++.h>
#define gibon cin.tie(0); ios::sync_with_stdio(false);
#define ll long long
using namespace std;
char A[101010];
int Pref[101010];
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        int N, X;
        cin >> N >> X;
        cin >> A;
        Pref[0]=0;
        for(int i=0;i<N;i++)
        {
            if(A[i]=='0')
                Pref[i+1]=Pref[i]+1;
            else
                Pref[i+1]=Pref[i]-1;
        }
        if(Pref[N]==0)
        {
            bool jogun=false;
            for(int i=0;i<N;i++)
            {
                if(Pref[i]==X)
                    jogun=true;
            }
            if(jogun)
                cout << -1 << '\n';
            else
                cout << 0 << '\n';
            continue;
        }
        int tmp=X%Pref[N];
        int ans=0;
        if(Pref[N]>0)
        {
            for(int i=0;i<N;i++)
            {
                if(Pref[i]<=X && (X-Pref[i])%Pref[N]==0)
                    ans++;
            }
        }
        else
        {
            for(int i=0;i<N;i++)
            {
                if(Pref[i]>=X && (Pref[i]-X)%Pref[N]==0)
                    ans++;
            }
        }
        cout << ans << '\n';
    }
}