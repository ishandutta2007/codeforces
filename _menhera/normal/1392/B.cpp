    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int T; scanf("%d", &T);
        while(T--)
        {
            int N; long long K; scanf("%d%lld", &N, &K);
            if(K > 2) K = K%2 + 2;
            vector<long long> arr;
            for(int i=0; i<N; ++i)
            {
                int t; scanf("%d", &t);
                arr.push_back((long long)t);
            }
            for(int a=0;a<K; ++a)
            {
                int me = *max_element(arr.begin(), arr.end());
                for(auto &c: arr) c = me-c;
            }
            for(auto x: arr) printf("%lld ", x);
            puts("");
        }
    }