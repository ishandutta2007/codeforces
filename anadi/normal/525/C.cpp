#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long int l[100005];

int main() {
    int n;
    scanf("%d", &n);
    long long int first_pair=0, second_pair=0;
    long long int max_area=0;
    for(int i=0;i<n;++i)
        scanf("%I64d", &l[i]);
    sort(l,l+n);
    for(int i=n-1;i>0;--i){
        if((l[i]-l[i-1])<=1){
            if(first_pair==0){
                first_pair=l[i-1];
                --i;
            }
            else{
                second_pair=l[i-1];
                max_area+=first_pair*second_pair;
                first_pair=0;
                second_pair=0;
                --i;
            }
        }
    }
    printf("%I64d\n", max_area);
    return 0;
}