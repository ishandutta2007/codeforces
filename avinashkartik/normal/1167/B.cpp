#include<bits/stdc++.h>

using namespace std;

const int N = 200043;

int a[] = {4, 8, 15, 16, 23, 42};
vector <int> ans;
int w,x,y,z,n;

int main(){
	for(int k = 0; k < 2; k++){
		fflush(stdout);
	    printf("? %d %d\n",3*k+1,3*k+2);
	    cin>>n;
	    for(int i = 0; i < 6; i++){
	        for(int j = 0; j < 6; j++){
	        	if(a[i]*a[j] == n){
	            	x = a[i];
	            	y = a[j];
	        	}
	        }
	    }
	    fflush(stdout);
	    printf("? %d %d\n",3*k+1,3*k+3);
	    cin>>n;
	    for(int i = 0; i < 6; i++){
	        for(int j = 0; j < 6; j++){
	        	if(a[i]*a[j] == n){
	            	w = a[i];
	            	z = a[j];
	        	}
	        }
	    }
	    if(x == w || x == z){
	        ans.push_back(x);
			ans.push_back(y);
			ans.push_back(n/x);
		}
	    else{
	        ans.push_back(y);
			ans.push_back(x);
			ans.push_back(n/y);
		}
	}
	fflush(stdout);
	printf("! ");
	for(int i = 0; i < 6; i++)
	    printf("%d ",ans[i]);
	printf("\n");
}