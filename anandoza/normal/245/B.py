url = raw_input()

if url.startswith("http"):
  nothing, protocol, url = url.partition("http")
else:
  nothing, protocol, url = url.partition("ftp")

domain, ru, context = url[1:].partition("ru")
domain = url[0] + domain

if context:
  print protocol + "://" + domain + "." + ru + "/" + context
else:
  print protocol + "://" + domain + "." + ru