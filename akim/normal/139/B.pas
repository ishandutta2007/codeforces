var a:array[1..600,1..3]of longint;
    cd,b1,b2,b3,n,m,i,w,h,f,s,kol:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  readln(w,h,a[i,2]);
  a[i,1]:=(w+h)*2;
  a[i,3]:=$7fffffff;
 end;
 readln(m);
 for i:=1 to m do
 begin
  readln(b1,b2,b3);
  for f:=1 to n do
  begin
   if b1<a[f,2] then continue;
   kol:=b1 div a[f,2];
   cd:=a[f,1] div (kol*b2);
   if a[f,1] mod (kol*b2)<>0 then inc(cd);
   cd:=cd*b3;
   if cd<a[f,3] then a[f,3]:=cd;
  end;
 end;
 s:=0;
 for i:=1 to n do
  inc(s,a[i,3]);
 writeln(s);
end.