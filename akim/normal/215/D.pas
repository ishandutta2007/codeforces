var t,tm,x,c,mid,n:int64;i:longint;
    s:int64;
function vich:int64;
var o:int64;
begin
 if tm-t>0 then if mid mod (tm-t)>0 then o:=1 else o:=0;
 if tm-t<=0 then o:=mid*x+c else if mid*x+c<(mid div(tm-t)+o)*c then o:=mid*x+c else o:=(mid div(tm-t)+o)*c;
 vich:=o;
end;
begin
 readln(n,mid);
 for i:=1 to n do
 begin
  read(t,tm,x,c);
  s:=s+vich;
 end;
 writeln(s);
end.