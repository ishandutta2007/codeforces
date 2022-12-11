var a,z:array[1..110,1..110]of boolean;
    b:array[1..110]of longint;
    n,m,k,i,f,s,x,y:longint;log:boolean;
begin
 readln(n,m);
 for i:=1 to m do
 begin
  read(x,y);
  a[x,y]:=true;
  a[y,x]:=true;
 end;s:=0;log:=true;
 while log do
 begin
  z:=a;
  log:=false;
  for i:=1 to n do
  begin
   k:=0;
   for f:=1 to n do
    if z[i,f]=true then begin inc(k);if k=2 then break;end;
   if k=1 then 
   begin
    log:=true;
    for f:=1 to n do
     if a[i,f]=true then begin a[i,f]:=false;a[f,i]:=false;end;
   end;
  end;
  if log=true then inc(s);
 end;
 writeln(s);
end.