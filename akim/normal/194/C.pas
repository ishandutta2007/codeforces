var a:array[0..100,0..100]of char;
    z:array[0..100,0..100]of longint;
    fx,fy,i,f,k,n,m,min,s,t:longint;fl:boolean;
function mina(x,y:longint):longint;
begin mina:=x;if y<x then mina:=y;end;
function dfs(x,y:longint):longint;
var p,o:longint;
begin
 z[x,y]:=t;p:=t;inc(t);
 if (a[x,y+1]='#') then 
 begin 
  if (x=fx)and(y=fy)and(z[x,y+1]=0) then 
   if not(fl) 
   then 
    fl:=true 
   else 
   begin 
    writeln(1);halt(0);
   end;
  if (z[x,y+1]=0) then 
  begin 
   o:=dfs(x,y+1);
   if (o>=z[x,y])and(z[x,y]<>1) then begin writeln(1);halt(0);end;
   p:=mina(p,o);
  end 
  else p:=mina(p,z[x,y+1]);
 end;
 if (a[x+1,y]='#') then 
 begin 
  if (x=fx)and(y=fy)and(z[x+1,y]=0) then
   if not(fl) 
   then 
    fl:=true
   else
   begin
    writeln(1);halt(0);
   end;
  if (z[x+1,y]=0) then  
  begin 
   o:=dfs(x+1,y);
   if (o>=z[x,y])and(z[x,y]<>1) then begin writeln(1);halt(0);end;
   p:=mina(p,o);
  end 
  else p:=mina(p,z[x+1,y]);
 end;
 if (a[x,y-1]='#') then 
 begin 
  if (x=fx)and(y=fy)and(z[x,y-1]=0) then
   if not(fl) 
   then 
    fl:=true
   else 
   begin 
    writeln(1);halt(0);
   end;
  if (z[x,y-1]=0) then 
  begin 
   o:=dfs(x,y-1);
   if (o>=z[x,y])and(z[x,y]<>1) then begin writeln(1);halt(0);end;
   p:=mina(p,o);
  end 
  else p:=mina(p,z[x,y-1]);
 end;
 if (a[x-1,y]='#') then
 begin 
  if (x=fx)and(y=fy)and(z[x-1,y]=0) then 
   if not(fl) 
   then  
    fl:=true
   else 
   begin 
    writeln(1);halt(0);
   end;
  if (z[x-1,y]=0) then 
  begin 
   o:=dfs(x-1,y);
   if (o>=z[x,y])and(z[x,y]<>1) then begin writeln(1);halt(0);end;
   p:=mina(p,o);
  end 
  else p:=mina(p,z[x-1,y]);
 end;
 dfs:=p;
end;
begin
 readln(n,m);min:=5;s:=0;fl:=false;
 for i:=1 to n do
 begin
  for f:=1 to m do
  begin
   read(a[i,f]);
   if a[i,f]='#' then begin inc(s);if s=1 then begin fx:=i;fy:=f;end;end;
  end;
  readln;
 end;
 if s<3 then begin writeln('-1');halt(0);end;
{ for i:=1 to n do
  for f:=1 to m do
  begin
   if a[i,f]='#' then
   begin
    k:=0;
    if a[i,f+1]='#' then inc(k);
    if a[i,f-1]='#' then inc(k);
    if a[i+1,f]='#' then inc(k);
    if a[i-1,f]='#' then inc(k);
    if k<min then min:=k;
   end;
  end;}
 t:=1;
 {if min=2 then }dfs(fx,fy);
 writeln({min}2);
end.