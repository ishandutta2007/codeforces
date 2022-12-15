#include <stdio.h>
#include <algorithm>
#include <utility>

typedef long long ll;
typedef std::pair<int, int> iPair;

int n, m;
ll arr[100000], t[100000];

iPair last[100000];

bool Check(int day) {
    for(int i = 0; i < m; i++) last[i].first = -1;
    for(int i = day; i >= 0; i--) {
        if(last[arr[i] - 1].first == -1) {
            last[arr[i] - 1].first = i;
            last[arr[i]-1].second = t[arr[i]-1];
        }
    }
    bool flag = true;
    for(int i = 0; i < m; i++) {
        if(last[i].first == -1) {
            flag = false;
            break;
        }
    }
    if(!flag) return false;

    int d = 0;
    std::sort(last, last + m);
    for(int i = 0; i < m; i++) {
        if(i == 0) d = last[i].first;
        else d += last[i].first - last[i-1].first - 1;
        d -= last[i].second;
        if(d < 0) return false;
    }

    return true;
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%lld", arr + i);
    for(int i = 0; i < m; i++) scanf("%lld", t + i);

    int min = 0, max = n - 1;  
    if(!Check(max)) printf("-1\n");
    else {
        while(max - min > 1) {
            int mid = (min + max) / 2;
            if(Check(mid)) 
                max = mid;
            else
                min = mid;
        }
        printf("%d\n", max + 1);
    }

    return 0;
}