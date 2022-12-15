#include <stdio.h>
#include <utility>
#include <algorithm>

long long n, k, s, t;
typedef std::pair<long long, long long> iPair;

long long gas[200100];
iPair arr[200100];

bool Check(long long cap) {
    long long tt = 0, ss = 0;
    for(int i = 0; i < k; i++) {
        long long length = (gas[i] - ss);
        long long cc = (cap - length);
        if(cc > length) cc = length;
        if(cc < 0) return false;
        tt += cc + (length - cc) * 2ll;
        ss = gas[i];
    }
    long long length = (s - ss);
    long long cc = (cap - length);
    if(cc > length) cc = length;
    if(cc < 0) return false;
    tt += cc + (length - cc) * 2ll;

    if(tt > t) return false;
    else return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%lld %lld %lld %lld", &n, &k, &s, &t);
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &arr[i].second, &arr[i].first);
    }
    std::sort(arr, arr + n);
    for(int i = 0; i < k; i++) {
        scanf("%lld", gas + i);
    }
    std::sort(gas, gas + k);
    
    long long min = -1, max = n - 1;
    while(max - min > 1) {
        int mid = (min + max) / 2;
        if(Check(arr[mid].first)){
            max = mid;
        }
        else
            min = mid;
    }

    while(max > 0) {
        if(arr[max-1].first != arr[max].first) break;
        max--;
    }

    if(Check(arr[max].first)) {
        long long mm = 2016147541;
        for(int i = max; i < n; i++) {
            if(mm > arr[i].second) mm = arr[i].second;
        }   
        printf("%d\n", mm);
    }
    else
        printf("-1\n");

    return 0;
}