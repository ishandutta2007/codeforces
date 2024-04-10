var s:string;l,k,p,i:longint;
begin
 readln(s);l:=length(s);k:=0;p:=0;
 for i:=2 to l do
 begin
  inc(k);if k=5 then begin inc(p);k:=0;end;
  if s[i]=s[i-1] then else if k<>0 then begin inc(p);k:=0;end;
 end;
 inc(p);
 writeln(p);
end.