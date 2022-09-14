#include <cstdio>

const int N = 200000;

int sw, hmax1, hmax2, imax;
int w[N];

int main() {
    int n; hmax1 = hmax2 = -1; sw = 0;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        int h; scanf("%d%d",&(w[i]),&h);
        sw+=w[i];
        if (h>hmax1) { hmax2=hmax1; hmax1=h; imax=i; }
        else if (h>hmax2) { hmax2=h; }
    }
    for (int i=0; i<n; i++) {
        printf("%d ",(sw-w[i])*((i==imax)?hmax2:hmax1));
    }
    return 0;
}