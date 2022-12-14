var
 n,sc,k,r,sqx,l,ans:int64;
 i,j:longint;
begin
 readln(n,k);
 sqx:=trunc(sqrt(n));
 for i:=1 to  sqx do if n mod i =0 then
 begin
 inc(sc);
 if i<>n div i  then inc(sc);
 end;
 if sc<k then begin writeln(-1); halt; end;

 l:=0;
 r:=sc+1;
 for i:=1 to sqx  do   if n mod i=0 then
 begin
  inc(l);
  if l=k then begin writeln(i); halt; end;
  if i<>n div i then dec(r);
  if r=k then begin writeln(n div i); halt; end;
 end;
end.