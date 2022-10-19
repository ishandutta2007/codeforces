#include <bits/stdc++.h>
#define maxn 300300
#define ll long long
using namespace std;

int main(){
    
    int n;
    scanf("%d",&n);
    
    int a=0, b=0;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(x == 1) a++;
        else b++;
    }
    
    if(a >= 3){
        printf("1 1 1 "); a-= 3;
        while(b--) printf("2 ");
        while(a--) printf("1 ");
        return 0;
    }
    else {
        if(a){
            if(b) {printf("2 "); b--;}
            printf("1 "); a--;}
         while(b--) printf("2 ");
        while(a--) printf("1 ");
        return 0;
    
    }
    
}