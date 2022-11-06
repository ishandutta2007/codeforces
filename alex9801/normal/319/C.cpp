#include <stdio.h>
#include <deque>

const long long INF=9200000000000000000LL;

struct lin
{
    long long a;
    long long b;
    long long s;
    long long e;
    lin(long long aa=0,long long ab=0,long long as=1,long long ae=INF) : a(aa),b(ab),s(as),e(ae)
    {
    }
};

std::deque<lin> d;
int arr[100000][2];
long long cut[100000];

int main()
{
    int n,i;
    long long t;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i][0]);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i][1]);
    d.push_back(lin(arr[0][1],0));
    for(i=1;i<n;i++)
    {
        while(d.front().e<arr[i][0])
            d.pop_front();
        cut[i]=d.front().a*arr[i][0]+d.front().b;
        while((t=(cut[i]-d.back().b-1)/(d.back().a-arr[i][1]))<d.back().s)
            d.pop_back();
        d.back().e=t;
        d.push_back(lin(arr[i][1],cut[i],d.back().e+1));
    }
    printf("%I64d",cut[n-1]);
    return 0;
}