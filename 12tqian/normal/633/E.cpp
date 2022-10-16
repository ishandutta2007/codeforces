#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
static int v[MAX];
static int c[MAX];
static int grades[MAX];
static int maxs[MAX][(int) (log2(MAX) + 5)];
static int mins[MAX][(int) (log2(MAX) + 5)];
static long double binom[MAX];
static int n, k;
int rmax(int l, int r){
    int j = floor(log2(r - l+1));
    if(maxs[l][j] >= maxs[r - (1<<j) + 1][j]){
        return maxs[l][j];
    }
    return maxs[r - (1<<j) + 1][j];
}
int rmin(int l, int r){
    int j = floor(log2(r - l+1));
    if(mins[l][j] <= mins[r - (1<<j) + 1][j]){
        return mins[l][j];
    }
    return mins[r - (1<<j) + 1][j];
}
int bin(int l, int r){
    int l1 = l;
    if(v[l]>=c[l]){
        return -1;
    }
    if(rmin(l, n-1) >= rmax(l, n-1)){
        return -2;
    }
    while(l1<= r){
        //cout<< l1 << " " << r<< endl;
        int m = l1 + (r - l1)/2;
        if(rmin(l, m) < rmax(l, m)){
            r = m - 1;
        }
        else{
            l1 = m + 1;
        }
    }
    return r;
}

int main(){
    scanf("%d %d", &n, &k);

    for(int i = 0; i<n; i++){
        int d;
        scanf("%d", &d);
        v[i]  = d;
       v[i] = d*100;
    }
    for(int i = 0; i<n; i++){
        int d;
        scanf("%d", &d);
        c[i] = d;
    }
    binom[0] = 1;
    binom[1] = ((long double) (n-k))/n;
	for(int x = 2; x<n; x++){
        binom[x] = binom[x-1] *(n-k-x+1)/(n-x+1);
    }

    for(int i = 0; i<= log2(n); i++){
        for(int x = 0; x<=n - (1<< i); x++){
            if(i == 0){
                maxs[x][i] =  v[x];
                continue;
            }
            maxs[x][i] = max(maxs[x][i-1], maxs[x+(1<<(i-1))][i-1]);
        }
    }
    for(int i = 0; i<= log2(n); i++){
        for(int x = 0; x<=n - (1<< i); x++){
            if(i == 0){
                mins[x][i] =  c[x];
                continue;
            }
            mins[x][i] = min(mins[x][i-1], mins[x+(1<<(i-1))][i-1]);
        }
    }
    //cout<< rmax(0, 5) << " "<< rmin(0,5);
   for(int i = 0; i<n; i++){
        int x = bin(i, n-1);
      //  cout<< x << endl;
        if(x == -2){
            grades[i] = rmax(i, n-1);
            continue;
        }
        else if(x == -1){
            grades[i] = c[i];
            continue;
        }
        if(v[x] == c[x]){
            grades[i] = max(rmax(i, x), rmin(x, n-1));
        }
        else{
            grades[i] = max(rmax(i, x),rmin(i, x+1));
        }
    }
    int check = -1;
    sort(grades, grades+n);
    vector<int> change;
    int prev = -1;
    int in = 0;
    long double e = 0;
    for(int i = 0; i<n; i++){
        if(prev == -1){
            prev = grades[i];
            continue;
        }
        if(grades[i]!= prev){
            long double toMult = binom[in] -  binom[i];
            if(toMult <0){
                prev = grades[i];
                in = i;
                continue;
            }
            e += (toMult*prev);
            prev = grades[i];
            in = i;
           // cout<< e << "asdf" << endl;
        }
    }
    e += ((binom[in] -binom[n])*grades[n-1]);
    cout <<fixed<< e << endl;
    return 0;
}