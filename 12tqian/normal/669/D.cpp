#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    int one = 0;
    int two = 1;
    for(int i = 0; i<q; i++){
        int temp;
        scanf("%d", &temp);
        if(temp == 1){
            int x;
            scanf("%d", &x);
            one += x;
            one += 8*n;
            one = one %n;
            two += x;
            two += 8*n;
            two = two%n;
        }
        else{
            if(one%2 == 0){
                one += (n+1);
                two -= (-n+1);
                one = one %n;
                two = two%n;
            }
            else{
                one -= (-n+1);
                two += (+n+1);
                one = one %n;
                two = two%n;
            }
        }
    }
    int s1, s2;
    if(one%2 == 0){
        s1  = (n-one)+1;
    }
    else{
        s2 =  (n-one)+1 +1;
    }
    if(two%2 == 0){
        s1  = (n-two)+2;
    }
    else{
        s2 = 1 +2+ (n-two);
    }
   // cout<<one<<s1<<endl;
   // cout<<two<<s2<< endl;
    for(int i = 0; i<n/2; i++){
        cout<< (s1+ 2*i-1)%n+1 <<" "<< (s2+ 2*i-1)%n+1<< " ";
    }
    return 0;
}