var n,m:longint;
begin
 read (n,m);
 if m=0 then begin write (n,' ',n); exit; end;
 if n=0 then begin write ('Impossible'); exit; end;
  if n+m-n>n then write (n+(m-n),' ') else write (n,' ');
  write (n+m-1);
end.