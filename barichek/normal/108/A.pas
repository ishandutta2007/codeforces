uses math;
var
  s:ansistring;
  h,m:longint;
begin
  read(s);
  h:=(ord(s[1])-48)*10+ord(s[2])-48;
  m:=(ord(s[4])-48)*10+ord(s[5])-48;
  repeat
    inc(m);
    if m=60 then begin m:=0; inc(h); end;
    if h=24 then h:=0;
    if h=(m mod 10)*10+m div 10 then
      begin
        if h div 10<>0 then write(h,':')
        else write('0',h,':');
        if m div 10<>0 then write(m)
        else write(0,m);
        halt;
      end;
  until h=-1;
end.