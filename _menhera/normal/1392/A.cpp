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
            int t; scanf("%d", &t);
            arr.push_back(t);
        }
        bool f = true;
        for(auto x: arr)
            if(x != arr[0])
                f = false;
        if(!f) puts("1");
        else printf("%d\n", N);
    }
}