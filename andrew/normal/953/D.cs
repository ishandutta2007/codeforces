using System;
class Program
{
    static void Main()
    {
        string str;
        //int n = Convert.ToInt32(Console.ReadLine());
        int[,] a = new int[101,101];
        int[,] b = new int[101,101];
        char[,] cc = new char[101,101];
       System.Int32 i;
        System.Int32 j;
        System.Int32 y;
        System.Int32 x;
        System.Int32 mx;
        y = 0;
        x = 0;
  
        mx = 0;
        a[1,1] = 3;a[1,2] = 3;a[1,7] = 3;a[1,8] = 3;
        a[2,1] = 3;a[2,2] = 3;a[2,7] = 3;a[2,8] = 3;
        a[3,4] = 3;a[3,5] = 3;
        a[4,4] = 3;a[4,5] = 3;
        a[1,4] = 4;a[1,5] = 4;
        a[2,4] = 4;a[2,5] = 4;
        a[3,1] = 2;a[3,2] = 2;a[3,7] = 2;a[3,8] = 2;
        a[4,1] = 2;a[4,2] = 2;a[4,7] = 2;a[4,8] = 2;
        a[5,4] = 2;a[5,5] = 2;
        a[6,4] = 2;a[6,5] = 2;
        a[5,1] = 1;a[5,2] = 1;a[5,7] = 1;a[5,8] = 1;
        a[6,1] = 1;a[6,2] = 1;a[6,7] = 1;a[6,8] = 1;
        for(i = 1; i <= 6; i++)
        {
                                 string s = Console.ReadLine();
        
         for(j = 1; j <= 8; j++){
              b[i,j] = -1;
              cc[i,j] = s[j - 1];
              if((j) % 3 == 0)continue;
              if(cc[i,j] == '.')b[i,j] = 0; else b[i,j] = 1;
              if(b[i,j] == 0){
                    if(a[i,j] > mx){
                        mx = a[i,j];
                        y = i;
                        x = j;
                    }
              }
         }
        }
         cc[y,x]='P';
         for(i = 1; i <= 6; i++){
            for(j = 1; j <= 8; j++){
            Console.Write(cc[i,j]);
            }
           // Console.Write("True");
            Console.WriteLine();
         }
    }

}