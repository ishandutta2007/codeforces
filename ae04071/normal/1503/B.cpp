#include <bits/stdc++.h>
using namespace std;

int n;

bool inc(int &i, int &j) {
    j+=2;
    if(j>=n) {
        i++;
        if(i>=n) return true;
        if(j%2==0) j=1;
        else j=0;
    }
    return false;
}

int main() {
    scanf("%d",&n);

    bool f=false;
    int c, i[2]={0,}, j[2]={0,1};
    for(int t=0;t<n*n;t++) {
        scanf("%d",&c);
        if(!f) {
            if(c!=1) {
                printf("1 %d %d\n",i[0]+1, j[0]+1);
                f = inc(i[0], j[0]);
            }
            else {
                printf("2 %d %d\n",i[1]+1, j[1]+1);
                f = inc(i[1], j[1]);
            }
            fflush(stdout);
        } else {
            if(i[0]>=n) {
                if(c==2) {
                    printf("3 %d %d\n",i[1]+1, j[1]+1);
                    inc(i[1], j[1]);
                } else {
                    printf("2 %d %d\n",i[1]+1, j[1]+1);
                    inc(i[1], j[1]);
                }
            } else {
                if(c==1) {
                    printf("3 %d %d\n",i[0]+1, j[0]+1);
                    inc(i[0], j[0]);
                } else {
                    printf("1 %d %d\n",i[0]+1, j[0]+1);
                    inc(i[0], j[0]);
                }
            }
        }
        fflush(stdout);
    }
}