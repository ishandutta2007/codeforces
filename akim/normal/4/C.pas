type str=record
          st:string;
          po:longint;
         end;
var a:array[1..200000]of str;
    n,l,i,f:longint;
    s:string;
    log:boolean;
begin
 readln(n);l:=0;
 for i:=1 to n do
 begin
  readln(s);
  log:=true;
  for f:=1 to l do
   if a[f].st=s then begin
                      write(s);
                      writeln(a[f].po);
                      inc(a[f].po);
                      log:=false;
                      break;
                     end;
  if log then begin inc(l);a[l].st:=s;a[l].po:=1;writeln('OK');end;
 end;
end.