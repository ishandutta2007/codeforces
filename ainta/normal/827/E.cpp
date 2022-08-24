#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
int TC, n;
char p[610000];


const int A = 7, B = 26, P = A << B | 1, R = 3;
int SZ, N;

int X[1100000], Y[1100000];

int Pow(int x, int y) {
    int r = 1;
    while (y) {
        if (y & 1) r = (long long)r * x % P;
        x = (long long)x * x % P;
        y >>= 1;
    }
    return r;
}

void FFT(int *a, bool f) {
    int i, j, k, x, y, z;
    j = 0;
    for (i = 1; i < N; i++) {
        for (k = N >> 1; j >= k; k >>= 1) j -= k;
        j += k;
        if (i < j) {
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }
    }
    for (i = 1; i < N; i <<= 1) {
        x = Pow(f ? Pow(R, P - 2) : R, P / i >> 1);
        for (j = 0; j < N; j += i << 1) {
            y = 1;
            for (k = 0; k < i; k++) {
                z = (long long)a[i | j | k] * y % P;
                a[i | j | k] = a[j | k] - z;
                if (a[i | j | k] < 0) a[i | j | k] += P;
                a[j | k] += z;
                if (a[j | k] >= P) a[j | k] -= P;
                y = (long long)y * x % P;
            }
        }
    }
    if (f) {
        j = Pow(N, P - 2);
        for (i = 0; i < N; i++) a[i] = (long long)a[i] * j % P;
    }
}
int ck[601000];

int main(){
    int i, j;
    scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n);
        scanf("%s",p);
        SZ = 0;
        while((1<<SZ) < n*2)SZ++;
        N = 1<<SZ;
        for(i=0;i<N;i++)X[i]=Y[i]=0;
        for(i=0;i<n;i++){
            if(p[i] == 'V'){
                X[i] = 1;
            }
            if(p[i] == 'K'){
                Y[n-i-1] = 1;
            }
            ck[i] = 0;
        }
        ck[n] = 0;
        FFT(X, false);
        FFT(Y, false);
        for(i=0;i<N;i++)X[i] = (long long)X[i]*Y[i]%P;
        FFT(X, true);
        for(i=0;i<N;i++){
            if(X[i]){
                ck[abs(n-i-1)] = 1;
            }
        }
        vector<int>res;
        for(i=n;i>=1;i--){
            for(j=i;j<=n;j+=i){
                if(ck[j])break;
            }
            if(j>n)res.push_back(i);
            else ck[i]=1;
        }
        printf("%d\n",res.size());
        for(i=res.size()-1;i>=0;i--)printf("%d ",res[i]);
        printf("\n");
    }
}