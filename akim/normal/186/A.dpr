var s,t:ansistring;
    i,f,sl,tl:longint;
    c1,c2,c3,c4:char;
    log1,log2:boolean;
begin
 log1:=false; log2:=false;
 readln(s);
 readln(t);
 sl:=length(s);
 tl:=length(t);
 if (sl=1)or(sl<>tl) then begin writeln('NO');halt(0);end;
 for i:=1 to sl do
  if s[i]<>t[i] then begin f:=i+1;c1:=s[i];c2:=t[i];log1:=true;break;end;
 if log1 then
 for i:=f to sl do
  if s[i]<>t[i] then begin f:=i+1;c3:=s[i];c4:=t[i];if (c3<>c2)or(c4<>c1) then begin writeln('NO');halt(0);end;log2:=true;break;end;
 if not(log2) then begin writeln('NO');halt(0);end;
 for i:=f to sl do
  if s[i]<>t[i] then begin writeln('NO');halt(0);end;
 writeln('YES');
end.