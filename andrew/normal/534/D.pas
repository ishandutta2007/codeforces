var
 a,b,st:array[0..200000]of longint;
 c,stn,i,j,n,k:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(c);
  a[i]:=b[c];
  b[c]:=i;
 end;

 while j>=0 do if b[j]<>0 then
 begin
  inc(stn);
  st[stn]:=b[j];
  b[j]:=a[b[j]];
  inc(j);
 end else dec(j,3);

 if stn<>n then
 begin
  writeln('Impossible');
  halt;
 end;

 writeln('Possible');
 for i:=1 to n do write(st[i],' ');
end.