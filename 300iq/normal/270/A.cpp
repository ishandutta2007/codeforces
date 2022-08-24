    #include <iostream>
    #include <algorithm>
    using namespace std;
    int main()
    {
        int n ;          int a;
        cin>>n;
        string answ[180];
       for(int i = 0; i<n; i++){

            cin>>a;
             if (360 % (180 - a) == 0){
                answ[i]="YES";
             }
             else{
                answ[i]="NO";
             }

       }
       int i = 0;
       while(answ[i]=="YES"||answ[i]=="NO"){
        cout<<answ[i]<<endl;
        i+=1;
       }

    }