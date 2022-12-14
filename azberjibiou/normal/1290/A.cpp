#include <bits/stdc++.h>
#define gibon cin.tie(0); ios::sync_with_stdio(false);
using namespace std;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        int N, M, K;
        int A[5050]={};
        int B[5050]={};
        cin >> N >> M >> K;
        K=min(K, M-1);
        for(int i=0;i<N;i++)    cin >> A[i];
        for(int i=0;i<M;i++)
            B[i]=max(A[i], A[N-M+i]);
        multiset <int> s;
        for(int i=K;i<M;i++)
            s.insert(B[i]);
        int ans=*(s.begin());
        for(int i=K-1;i>=0;i--)
        {
            auto it=s.find(B[M-K+i]);
            s.erase(it);
            s.insert(B[i]);
            ans=max(ans, *(s.begin()));
        }
        cout << ans << '\n';
    }
}