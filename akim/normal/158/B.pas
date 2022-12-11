var n,i,f,k,s:longint;
    a:array[1..4]of longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(k);
  inc(a[k]);
 end;
 s:=a[4];
 a[4]:=0;
 s:=s+a[3];
 a[1]:=(a[1]-a[3]);
 a[3]:=0;
 if a[1]<0 then a[1]:=0;
 if a[2] mod 2=1 then
 begin
  s:=s+a[2] div 2+1;
  a[1]:=a[1]-2;
  if a[1]<0 then a[1]:=0;
 end else 
  s:=s+a[2] div 2;
 if a[1] mod 4=0 then
  s:=s+a[1] div 4 else
  s:=s+a[1] div 4+1;
 writeln(s);
end.