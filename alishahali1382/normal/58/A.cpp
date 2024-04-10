#include <iostream>
#include <string>

using namespace std;

string s;

main(){
	cin>>s;
	int n=s.size();
	int x=0;
	for (int i=0; i<n; i++){
        if (x==5){
            cout<<"YES"<<endl;
            return 0;
        }
        else if (x==0){
            if (s[i]=='h') x++;
        }
        else if (x==1){
            if (s[i]=='e') x++;
        }
        else if (x==2){
            if (s[i]=='l') x++;
        }
        else if (x==3){
            if (s[i]=='l') x++;
        }
        else if (x==4){
            if (s[i]=='o') x++;
        }
	}
    if (x==5){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}