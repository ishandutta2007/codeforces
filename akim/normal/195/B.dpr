var a,b,c,l,r,i:longint;
    log:boolean;
begin
 readln(a,b);
 c:=(b+1) div 2;
 if b mod 2=1 then begin log:=true;l:=-1;r:=0;end else begin log:=false;l:=1;r:=0;end;
 for i:=1 to a do
 begin
  if r mod 2=1 then begin c:=c+l*r;writeln(c);end else begin c:=c-l*r;writeln(c);end;
  inc(r);
  if r=b then begin r:=0;c:=(b+1) div 2;end;
 end;
end.