var a:array[1..1100]of longint;
    x:array[1..1000]of extended;
    b,c,i,f,n,m,k,l,p:longint;
    z1,z2:extended;
begin
 readln(n,m,k,l);
 for i:=1 to n do
 begin
  readln(b,c);
  a[i]:=i;
  z1:=b*m*((100-l)/100)+c*k;
  z2:=c*m*((100-l)/100)+b*k;
  if z1<z2 then x[i]:=z2 else x[i]:=z1;
 end;
 for i:=1 to n-1 do
 for f:=i+1 to n do
  if x[i]<x[f] then begin
                     z1:=x[i];
                     x[i]:=x[f];
                     x[f]:=z1;
                     p:=a[i];
                     a[i]:=a[f];
                     a[f]:=p;
                    end else
  if x[i]=x[f] then
  if a[i]>a[f] then begin
                     p:=a[i];
                     a[i]:=a[f];
                     a[f]:=p;
                    end;
 for i:=1 to n do
  writeln(a[i],' ',x[i]:1:2);
end.