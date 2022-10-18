#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define maxN 1200

int main(){
    int i,j,k,l,m,n,tm;
    int ohYeah[maxN], nofucksgiven[maxN], thisIsSomeSeriousShit[maxN], hp;
    int res[maxN], use_tm[maxN], res_size;
    int maxHP, reg, mx;

    scanf("%d%d%d",&n,&maxHP,&reg);
    for(i=0;i<n;i++) scanf("%d%d",thisIsSomeSeriousShit+i,nofucksgiven+i);

    hp = maxHP;
    for(i=0;i<n;i++) ohYeah[i]=0;
    res_size=0;

    for(tm=0;;tm++){
        int fg=0, bef_hp = hp;

        for(i=0;i<n;i++) if(ohYeah[i]) hp -= nofucksgiven[i];
        hp += reg;
        if(hp > maxHP) hp = maxHP;

        if(hp<=0) break;

        mx = 0;
        for(i=0;i<n;i++) if(!ohYeah[i]) if(thisIsSomeSeriousShit[i]*maxHP >= hp*100) if(mx < nofucksgiven[i]){
            mx = nofucksgiven[i]; k = i;
        }
        if(mx){
            fg++;
            ohYeah[k] = 1;
            res[res_size]=k+1; use_tm[res_size] = tm;
            res_size++;
        }

        if(bef_hp > hp) fg++;

        if(!fg) break;
    }

    if(hp > 0)puts("NO");
    else{
        puts("YES");
        printf("%d %d\n",tm,res_size);
        for(i=0;i<res_size;i++) printf("%d %d\n",use_tm[i],res[i]);
    }

    return 0;
}