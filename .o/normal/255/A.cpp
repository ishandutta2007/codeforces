#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<memory.h>
#include<map>
#include<assert.h>

int n;
int a[3],r;
char res[3][20]={"chest","biceps","back"};

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int d; scanf("%d",&d);
        a[i%3]+=d;
    }
    for(int i=1;i<3;i++){
        if(a[i]>a[r])r=i;
    }
    puts(res[r]);
    return 0;
}