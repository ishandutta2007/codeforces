#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>

const long long INF = 10000000000000000;

std::string str;
char s[100010];

int n;
int arr[100010];
int ind[100010];
long long cache[100010][2];

long long MinCost(int k, int pr)
{
    if(k == n) return 0;
    long long& ret = cache[k][pr];
    if(ret != -1) return ret;
    
    ret = INF;
    
    std::string prev(str.begin() + ind[k-1], str.begin() + ind[k]);
    if(pr) std::reverse(prev.begin(), prev.end());
    std::string now(str.begin() + ind[k], str.begin() + ind[k+1]);
    std::string rev(now.begin(), now.end());
    std::reverse(rev.begin(), rev.end());
    
    if(prev <= now)
        ret = std::min(ret, MinCost(k+1, 0));
    if(prev <= rev)
        ret = std::min(ret, MinCost(k+1, 1) + arr[k]);
    
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    
    for(int i = 0; i < n; i++)
    {
        ind[i] = (int)str.size();
        scanf("%s", s);
        str += s;
    }
    ind[n] = (int)str.size();
    
    memset(cache, -1, sizeof(cache));
    
    long long min = INF;
    min = std::min(min, MinCost(1,0));
    min = std::min(min, MinCost(1,1) + arr[0]);
    
    if(min >= INF) printf("-1\n");
    else printf("%I64d\n", min);
    
    return 0;
}