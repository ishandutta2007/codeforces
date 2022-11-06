#include<bits/stdc++.h>
using namespace std;

pair<int, int> arr[200010];

int gcd(int a, int b)
{
    return a ? gcd(b%a, a) : b;
}

int main()
{
    int m, i;
    scanf("%d", &m);
    
    map<pair<int, int>, int> cnt;
    
    for(i=0;i<m;i++)
    {
        int a, b, c;
        scanf(" (%d+%d)/%d", &a, &b, &c);
        
        int p = a+b;
        int q = c;
        int g = gcd(p, q);
        
        p /= g;
        q /= g;
       
        arr[i] = {p, q};
        
        cnt[arr[i]]++;
    }
    
    for(i=0;i<m;i++)
        printf("%d ", cnt[arr[i]]);
    return 0;
}