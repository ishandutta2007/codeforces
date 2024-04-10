var s1,s2:ansistring;
    l1,l2,lm,s,i,f:longint;
    log:boolean;
begin
 readln(s1);
 readln(s2);
 l1:=length(s1);
 l2:=length(s2);
 if l1<l2 then lm:=l1 else lm:=l2;
 for i:=lm downto 1 do
 begin
  if (l1 mod i=0)and(l2 mod i=0)then else continue;
  log:=true;
  for f:=1 to l2 do
   if f mod i<>0 then begin if s2[f]<>s1[f mod i] then begin log:=false;break;end;end else if s2[f]<>s1[i] then begin log:=false;break;end;
  if log then
  for f:=1 to l1 do
   if f mod i<>0 then begin if s1[f]<>s1[f mod i] then begin log:=false;break;end;end else if s1[f]<>s1[i] then begin log:=false;break;end;
  if log then inc(s);
 end;
 writeln(s);
end.