var a,b:array[-100..200,-100..200]of longint;
    n,m,i,f,g,h,o,bi,bf,bo:longint;c:char;
begin
 readln(n,m);
 for i:=1 to n do
 begin
  for f:=1 to m do
  begin
   read(c);
   if c='1' then a[i,f]:=1 else a[i,f]:=0;
  end;
  readln;
 end;
 readln(n,m);
 for i:=1 to n do
 begin
  for f:=1 to m do
  begin
   read(c);
   if c='1' then b[i,f]:=1 else b[i,f]:=0;
  end;
  readln;
 end;
 bi:=-51;bf:=-51;bo:=0;
 for i:=-50 to 50 do
  for f:=-50 to 50 do
  begin
   o:=0;
   for g:=1 to 50 do
    for h:=1 to 50 do
      o:=o+a[g,h]*b[g+i,h+f];
   if o>bo then begin bo:=o;bi:=i;bf:=f;end;
  end;
 writeln(bi,' ',bf);
end.