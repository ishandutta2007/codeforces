#include<stdio.h>
#include<map>
#include<string>
#include <iostream>

using namespace std;

map<string,int> day;
string p, q;

int main() {
 day["monday"] = 0;
 day["tuesday"] = 1;
 day["wednesday"] = 2;
 day["thursday"] = 3;
 day["friday"] = 4;
 day["saturday"] = 5;
 day["sunday"] = 6;

 cin >> p >> q;
 for(int d = 28; d <= 31; d++) if(d != 29) {
  if((day[p] + d - day[q]) % 7 == 0) return 0 & puts("YES");
 }
 puts("NO");
 return 0;
}