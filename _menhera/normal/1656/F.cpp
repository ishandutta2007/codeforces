#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N;
        vector<long long> A(N); for(auto &x: A) cin >> x;
        sort(A.begin(), A.end());

        vector<long long> S(N);
        S[0] = A[0];
        for(int i=1; i<N; ++i) S[i] = S[i-1] + A[i];

        long long min_slope = S[N-1] + (N-2)*A[0], max_slope = S[N-1] + (N-2)*A[N-1];
        if(min_slope > 0 || max_slope < 0)
        {
            cout << "INF" << endl;
            continue;
        }

        long long ans = LLONG_MIN;

        for(int p=0; p<N; ++p)
        {
            long long minv = A[0] - A[p], maxv = A[N-1] - A[p];
            long long rsum = S[N-1]-S[p] - (N-1-p)*A[p];
            long long lsum = S[p] - (p+1)*A[p];
            long long tot = minv*rsum+maxv*lsum-minv*maxv - (N-1)*A[p]*A[p];
            ans = max(ans, tot);
        }
        cout << ans << endl;
    }
}