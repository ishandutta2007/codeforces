#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int N; scanf("%d", &N);
        vector<int> arr;
        for(int i=0; i<N; ++i)
        {
            int t; scanf("%d", &t); arr.push_back(t);
        }
        long long ans = 0;
        for(int i=1; i<N; ++i)
        {
            if(arr[i] < arr[i-1]) ans += arr[i-1]-arr[i];
        }
        printf("%lld\n", ans);
    }
}