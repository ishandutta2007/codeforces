#include <iostream>
#include <cstdio>
using namespace std;

main(){
       
       long long a,b,m;
       cin >> a >> b >> m;
       
       if(a>=m || b>=m)
               {
                       printf("0\n");
                       return 0;
                       
                       }
       
       if(a<=0 && b<=0){
               printf("-1\n");
               return 0;
               }
       
       long long resp = 0;
       
       if(b > a)swap(a,b);
       
       if(b < 0){
               
               long long k = -b/a;
               b += a*k;
               resp += k;
               
               if(b < 0){
                    
                    b+=a;
                    resp++;
                    }
               
               
               }
               
       unsigned long long A = a;
       unsigned long long B = b;
       unsigned long long M = m;
               
       while(a < M && b < M){
               
               resp++;
               
               if(a >= M-b || b >= M-a)break;
               
               long long s = a + b;
               a = max(a,b);
               b = s;
               
               }
               
      cout << resp << endl;
     }