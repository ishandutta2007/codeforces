#include <cstdio>
#include <algorithm>

using namespace std;

bool pier[1005];

int main() {
    int n;
    scanf("%d", &n);
    int result=0;
    for(int i=2; i<=n; ++i){
        if(!pier[i]){
            ++result;
            for(int j=i+i; j<=n; j+=i)
                pier[j]=true;
            for(int j=i*i;j<=n; j*=i)
                ++result;
        }
    }
    printf("%d\n", result);
    for(int i=2; i<=n; ++i){
        if(!pier[i]){
            for(int j=i; j<=n; j*=i)
                printf("%d ", j);
        }
    }
    return 0;
}