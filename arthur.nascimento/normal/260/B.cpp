#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <assert.h>
#define debug
using namespace std;

int v[500100];
int tam[500100];
int ok=0;

int ndias[13]={
 -1 ,31,28,31,30,31,30,31,31,30,31,30,31
    
};
int freq[50][20][20];
int rd,rm,ra;
int best=0;

void check(int n){
debug("chech %d %d %d\n",v[n],v[n+1],v[n+2]);
 if(n<0)return;   
    if(tam[n] < 2 || tam[n+1]!=2 || tam[n+2]<4)return;
    
    int dia = v[n]%100 , mes = v[n+1] , ano=v[n+2];
    
    while(ano >= 10000)ano/=10;
    
    if(ano > 2015 || ano < 2013)return;
    if(mes<=0 || mes>12)return;
    if(ndias[mes] < dia || dia<=0)return;
    //;printf("%d-%d-%d\n",dia,mes,ano);
   
    freq[dia][mes][ano-2013]++;
    if(freq[dia][mes][ano-2013] > best){ok=1;
                                best = freq[dia][mes][ano-2013];
                                rd=dia;rm=mes;ra=ano;
                                }
    
}

main(){
       
       char ch;
       
       int n=0;
       while((ch=getchar())!='\n'){
                                   
                   if(ch=='-'){     check(n-2);           
                                   n++;
                                   
                                   continue;
                                   
                                   }    
                   
                   tam[n]++;
                   if(v[n] > 1000000){
                   int k = (v[n] % 10)*10 + ch-'0';
                   while(v[n]>10000)v[n]/=10;
                   v[n] = v[n]*100 + k;}
                   else
                   v[n] = ((v[n]*10) + ch-'0');
                                 
                                   
                                   }
                                 check(n-2);
       assert(ok);
       if(rd < 10)printf("0");
       printf("%d-",rd);
       if(rm<10)printf("0");
       printf("%d-%d\n",rm,ra);}