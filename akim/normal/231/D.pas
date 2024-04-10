var n,m,k,x1,y1,z1,a1,a2,a3,a4,a5,a6:int64;
begin
 readln(n,m,k);
 readln(x1,y1,z1);
 readln(a1,a2,a3,a4,a5,a6);
 if (n>0)and(n>x1)and(m>0)and(m>y1)and(k>0)and(k>z1) then writeln(a6+a4+a2);
 if (n>0)and(n>x1)and(m>0)and(m>y1)and(k>=0)and(k<=z1) then writeln(a6+a2);
 if (n>0)and(n>x1)and(m>0)and(m>y1)and(k<0)and(k<z1) then writeln(a6+a3+a2);
 if (n>0)and(n>x1)and(m>=0)and(m<=y1)and(k>0)and(k>z1) then writeln(a6+a4);
 if (n>0)and(n>x1)and(m>=0)and(m<=y1)and(k>=0)and(k<=z1) then writeln(a6);
 if (n>0)and(n>x1)and(m>=0)and(m<=y1)and(k<0)and(k<z1) then writeln(a6+a3);
 if (n>0)and(n>x1)and(m<0)and(m<y1)and(k>0)and(k>z1) then writeln(a6+a4+a1);
 if (n>0)and(n>x1)and(m<0)and(m<y1)and(k>=0)and(k<=z1) then writeln(a6+a1);
 if (n>0)and(n>x1)and(m<0)and(m<y1)and(k<0)and(k<z1) then writeln(a6+a3+a1);

 if (n>=0)and(n<=x1)and(m>0)and(m>y1)and(k>0)and(k>z1) then writeln(a4+a2);
 if (n>=0)and(n<=x1)and(m>0)and(m>y1)and(k>=0)and(k<=z1) then writeln(a2);
 if (n>=0)and(n<=x1)and(m>0)and(m>y1)and(k<0)and(k<z1) then writeln(a3+a2);
 if (n>=0)and(n<=x1)and(m>=0)and(m<=y1)and(k>0)and(k>z1) then writeln(a4);
 if (n>=0)and(n<=x1)and(m>=0)and(m<=y1)and(k<0)and(k<z1) then writeln(a3);
 if (n>=0)and(n<=x1)and(m<0)and(m<y1)and(k>0)and(k>z1) then writeln(a4+a1);
 if (n>=0)and(n<=x1)and(m<0)and(m<y1)and(k>=0)and(k<=z1) then writeln(a1);
 if (n>=0)and(n<=x1)and(m<0)and(m<y1)and(k<0)and(k<z1) then writeln(a3+a1);

 if (n<0)and(n<x1)and(m>0)and(m>y1)and(k>0)and(k>z1) then writeln(a5+a4+a2);
 if (n<0)and(n<x1)and(m>0)and(m>y1)and(k>=0)and(k<=z1) then writeln(a5+a2);
 if (n<0)and(n<x1)and(m>0)and(m>y1)and(k<0)and(k<z1) then writeln(a5+a3+a2);
 if (n<0)and(n<x1)and(m>=0)and(m<=y1)and(k>0)and(k>z1) then writeln(a5+a4);
 if (n<0)and(n<x1)and(m>=0)and(m<=y1)and(k>=0)and(k<=z1) then writeln(a5);
 if (n<0)and(n<x1)and(m>=0)and(m<=y1)and(k<0)and(k<z1) then writeln(a5+a3);
 if (n<0)and(n<x1)and(m<0)and(m<y1)and(k>0)and(k>z1) then writeln(a5+a4+a1);
 if (n<0)and(n<x1)and(m<0)and(m<y1)and(k>=0)and(k<=z1) then writeln(a5+a1);
 if (n<0)and(n<x1)and(m<0)and(m<y1)and(k<0)and(k<z1) then writeln(a5+a3+a1);
end.