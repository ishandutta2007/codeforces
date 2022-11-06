#include <iostream>
#include <cstring>

using namespace std;

long long n,m,w,i,j,mid;
long long a[100005],add[100005];

int check(long long h){
    memset(add,0,sizeof(add));

    long long wl = m,bonus=0,dif;
    for(size_t i=1;i<=n;i++){
        bonus += add[i];
        if(a[i]+ bonus < h){
            dif = h - a[i] - bonus;
            if(dif > wl) return 0;
            bonus += dif;
            add[min(i+w,n+1)] -= dif;
            wl -= dif;
        }
    }
    return 1;
}

int main()
{
    cin >> n >> m >> w;
    for(i=1;i<=n;i++) {
        cin >> a[i];
    }

    i = 0; j = 2000000000;
    do {
        mid = (i+j)/2;
        if(check(mid))
            i = mid + 1;
        else
            j = mid-1;
    }   while(i<=j);

    cout << j;

    return 0;
}