var a:array[1..1000]of longint;
    b:array[1..1000]of real;
    n,m,max,i:longint;z:real;
begin
 readln(n,m);
 max:=0;
 for i:=1 to n do
 begin
  read(a[i]);
  if a[i]>max then max:=a[i];
 end;
 for i:=1 to n do
 begin
  b[i]:=max-a[i];
  m:=m-trunc(b[i]);
 end;
 if m<0 then begin writeln(-1);halt(0);end;
 z:=m/n;
 for i:=1 to n do
  b[i]:=b[i]+z;
 for i:=1 to n do
  writeln(b[i]:1:6);
end.