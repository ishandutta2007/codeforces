var a,b,c,x,y,i:longint;
    t,t1,t2,min,s,s1:extended;
begin
 min:=0;
 readln(a,b,c);
 for i:=1 to a do
 begin
  readln(x,y);
  t:=y/b;
  s:=(b*sqr(t))/2;
  if s>c then t2:=x+sqrt((2*c)/b) else
  begin
   s1:=c-s;
   t1:=s1/y;
   t2:=t+t1+x;
  end;
  if min>t2 then writeln(min:1:10) else begin writeln(t2:1:10);min:=t2;end;
 end;
end.