#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h> 
using namespace std;




int main() {
	long long n;
	int k;
	cin >> n >> k;
	
	long long mn = 1, mx = n;
	bool poss = true;
	srand (time(NULL));
	while(poss){
		if(mx-mn > 50){
		
			long long md = (mn + mx)/2 + (rand()%3);
			cout << mn << " " << md << endl;
			fflush(stdout);
			string s;
			cin >> s;
			if(s=="Yes"){
				mx = md;
			}
			else{
				mn = md+1;
			}
			mn -= k;
			mx +=k;
			if(mn < 1) mn = 1;
			if(mx > n) mx = n;
		}
		
		else{

			long long guess = mn + (rand()%(mx-mn+1));
			cout << guess << " " << guess << endl;
			fflush(stdout);
			string s;
			cin >> s;
			if(s=="Yes"){
				return 0;
			}
			else{
				mn -= k;
				mx +=k;
				if(mn < 1) mn = 1;
				if(mx > n) mx = n;
			}
		}
	}
	
}