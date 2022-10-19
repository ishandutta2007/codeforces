#include <iostream>
#include <cstdio>
using namespace std;

int h[1001000];
int m[1001000];
string s;

main(){
       
       
       cin >> s;
       
       int t1 = 0;
       int t2 = 0;
       
       for(int i=0;i<(signed)s.length()-4;i++){
              
          //     cout << s.substr(i,5) << endl;
               
               if(s.substr(i,5) == "heavy")
                                h[t1++] = i;
                                
               
               if(s.substr(i,5) == "metal")
                                m[t2++] = i;
                                
                                
               
               }
       long long resp = 0;
       int pa=0,pb=0;
       
       while(pa != t1){
                
                if(h[pa] < m[pb] || pb == t2){
             //            printf("A");
                         resp+=(t2-pb);
                         
                         pa++;
                         }
                else {
               //      printf("B");
                     pb++;
                     }
                
                }
                
       cout << resp << endl;
                
                }