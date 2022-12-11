var a:array[1..100,1..100]of longint;
    c:array[1..100]of longint;
    d:array[1..10000,1..4]of longint;
    n,i,f,q,z,s,x,y,g:longint;
begin
 readln(n);
 for i:=1 to n do
 begin read(c[i]);s:=s+c[i];end;
 for i:=1 to n do
  for f:=1 to c[i] do
   read(a[i,f]);
 x:=1;y:=1;
 for g:=1 to s do
  for i:=1 to n do
   for f:=1 to c[i] do
   begin
    if (a[i,f]=g) then
    begin
     if (x<>i)or(y<>f) then
     begin
      inc(q);
      d[q,1]:=i;
      d[q,2]:=f;
      d[q,3]:=x;
      d[q,4]:=y;
      z:=a[i,f];
      a[i,f]:=a[x,y];
      a[x,y]:=z;
     end;
     inc(y);
     if y>c[x] then begin y:=1;inc(x);end;
    end;
   end;
 writeln(q);
 for i:=1 to q do
  writeln(d[i,1],' ',d[i,2],' ',d[i,3],' ',d[i,4]);
end.