var a,b:array[1..1000]of int64;
    n,m,i,f,q:longint;
begin
 readln(n,m);
 a[1]:=1;i:=2;
 while a[i-1]<=n do
 begin
  a[i]:=0;f:=i-1;
  while (f>=1)and(f>=i-m) do begin a[i]:=a[i]+a[f];dec(f);end;
  inc(i);
 end;
 dec(i,2);q:=0;
 for i:=i downto 1 do
  if a[i]<=n then begin n:=n-a[i];inc(q);b[q]:=a[i];end;
 if q=1 then inc(q);
 writeln(q);
 for i:=1 to q do
  write(b[i],' ');
end.