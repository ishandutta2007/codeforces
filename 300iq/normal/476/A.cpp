#include <iostream>

using namespace std;
int n, m, answ;
bool minus1 = true;
int main()
{
cin>>n>>m;
for(int i = 0; i<n; i++){
    if((n-2*i)+2*i == n){
        if((n-i)%m==0&&(2*i<=n)){
            minus1=false;
            answ = n-i;
        }
    }
}
if(minus1==true){
    cout<<-1;
}
else{
    cout<<answ;
}

}