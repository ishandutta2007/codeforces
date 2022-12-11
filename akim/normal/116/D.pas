{$o+,r-,s-,q-,i-}
var a:array[0..150,0..150]of longint;
    i,f,n,m,s,p,niz:longint;
    c:char;
begin
 readln(n,m);
 for i:=1 to n do
 begin
  for f:=1 to m do
  begin
   read(c);
   if c='W' then begin niz:=i;a[i,f]:=1;a[i-1,f]:=1;end;
  end;
  readln;
 end;
 p:=1;
 for i:=1 to niz do
 begin
  if i mod 2=1 then
  begin
   for f:=m downto p do
    if (a[i,f]=1)or(f=p) then begin s:=s+f-p+1;p:=f;break;end;
  end else
  begin
   for f:=1 to p do
    if (a[i,f]=1)or(f=p) then begin s:=s+p-f+1;p:=f;break;end;
  end;
 end;
 if s<>0 then dec(s);
 writeln(s);
end.