#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int turns(int h, int a, int d){
    if(a-d>0)
        return h%(a-d)==0 ? h/(a-d) : h/(a-d)+1;
    else return INT_MAX;
}

int main()
{
    int hpm, atkm, defm, hpy, defy, atky, hpl, atkl, defl, cost, min, surv, kills, tmp;
    scanf("%d%d%d%d%d%d%d%d%d", &hpy, &atky, &defy, &hpm, &atkm, &defm, &hpl, &atkl, &defl);
    surv = turns(hpy, atkm, defy);
    kills = turns(hpm, atky, defm);
    if(kills < surv){
        printf("0\n");
    }
    else{
        min = INT_MAX;
        tmp = max(0, defm-atky+1);
        for(int i=tmp; i<=200; i++){
            cost = i*atkl;
            kills = turns(hpm,atky+i,defm); 
            for(int j=0; j<200; j++){
                int lo, hi;
                lo = 0;
                hi = 50000;

                while(lo != hi){
                    int mid = (lo + hi)/2;
                    surv = turns(hpy+mid, atkm, defy+j);
                    if(surv <= kills)
                        lo = mid+1;
                    else
                        hi = mid;
                }
                cost += j*defl + lo*hpl;
                //printf("comprei: %d %d %d\n paguei: %d\n",i,j,lo,cost);
                if(cost < min){
                    min = cost;
                }
                cost = i*atkl;
            }
        }
        printf("%d\n", min);
    }
    return 0;
}